#include<bits/stdc++.h>

using namespace std;

class Object{
    public:
        string id;
        int x, y;
        char direction;
        int speed;
        string type;
        
        Object(string id, int x, int y, char direction, int speed, string type){
            this->id = id;
            this->x = x; this->y = y;
            this->direction = direction;
            this->speed =speed;
            this->type = type;
        }

        void move(){
            int dx = 0, dy = 0;
            switch (direction){
                case 'L':
                    dx = -1; break;
                case 'R':
                    dx = 1; break;
                case 'U':
                    dy = 1; break;
                case 'D':
                    dy = -1; break;
                default: break;
            }
            x += dx*speed;
            y += dy*speed;
        }

        void remove(){
            int dx = 0, dy = 0;
            switch (direction){
                case 'L':
                    dx = -1; break;
                case 'R':
                    dx = 1; break;
                case 'U':
                    dy = 1; break;
                case 'D':
                    dy = -1; break;
                default: break;
            }
            x -= dx*speed;
            y -= dy*speed;
        }

        void change(char direction, int speed){
            this->direction = direction;
            this->speed = speed;
        }
        void view_position(){
            cout << this->x << " " << this->y << endl;
        }
};

class Circle: public Object{
    public:
        int r;
        Circle(string id, int x, int y, int r, char direction, int speed):Object(id, x, y, direction, speed, "circle"){
            this->r = r;
        } 
};

class Rectangle: public Object{   
    public:
        int lx, ly;
        Rectangle(string id, int x, int y, int lx, int ly, char direction, int speed):Object(id, x, y, direction, speed, "rectangle"){
            this->lx = lx;
            this->ly = ly;
        } 
};

vector<Object*> objList;
unordered_map<Object*, bool> checkMap;

bool checkRec(Rectangle* rec0, Rectangle* rec1){
    if( abs(rec0->x - rec1->x) <= (rec0->lx + rec1->lx)
        && abs(rec0->y - rec1->y ) <= (rec0->ly + rec1->ly) ){
            return true;
    }
    return false;
}

bool checkRecCir(Rectangle* rec0, Circle* circle){
    // cout << "???";
    int x_;
    int y_;
    
    // check 4 đỉnh HCN----------
    x_ = rec0->x - rec0->lx; 
    y_ = rec0->y - rec0->ly;
    if( pow((x_ - circle->x), 2) + pow((y_ - circle->y), 2) <= pow(circle->r, 2)) return true;

    x_ = rec0->x + rec0->lx; 
    y_ = rec0->y - rec0->ly;
    if( pow((x_ - circle->x), 2) + pow((y_ - circle->y), 2) <= pow(circle->r, 2)) return true;

    x_ = rec0->x - rec0->lx; 
    y_ = rec0->y + rec0->ly;
    if( pow((x_ - circle->x), 2) + pow((y_ - circle->y), 2) <= pow(circle->r, 2)) return true;

    x_ = rec0->x + rec0->lx; 
    y_ = rec0->y + rec0->ly;
    if( pow((x_ - circle->x), 2) + pow((y_ - circle->y), 2) <= pow(circle->r, 2)) return true;
    
    if( abs((rec0->x - circle->x) <= rec0->lx) || abs((rec0->y - circle->y) <= rec0->ly) ){
        // cout << "collider" << endl;
        // cout << rec0->x << circle->x << rec0->lx << circle->r << endl;
        if( abs(rec0->x - circle->x) <= abs(rec0->lx + circle->r)
            && abs(rec0->y - circle->y ) <= abs(rec0->ly + circle->r) ){
                // cout << "collider" << endl;
                return true;
        }
    }
    return false;
}

bool checkCir(Circle* cir0, Circle* cir1){
    if( pow((cir0->x - cir1->x), 2) + pow((cir0->y - cir1->y), 2) <= pow((cir0->r + cir1->r), 2)){
            return true;
    }
    return false;
}

bool checkRecCollides(Rectangle* cur, vector<Object*> objList){
    for(auto obj : objList){
        if( checkMap[obj] == false){
            if( cur->id != obj->id){
                if( obj->type == "rectangle"){
                    Rectangle* rect = static_cast<Rectangle*>(obj);
                    if(checkRec(cur, rect)) {
                        checkMap[obj] = true;
                        return true;
                    }
                }
                else if( obj->type == "circle"){
                    Circle* circle = static_cast<Circle*>(obj);
                    if (checkRecCir(cur, circle)) {
                        checkMap[obj] = true;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool checkCirCollides(Circle* cur, vector<Object*> objList){
    for(auto obj : objList){
        if( cur->id != obj->id){
            if (obj->type == "rectangle"){
                Rectangle* rect = static_cast<Rectangle*>(obj);
                if( checkRecCir(rect, cur) ) return true;
            }
            else if (obj->type == "circle") {
                Circle* circle = static_cast<Circle*>(obj);
                if( checkCir(cur, circle) ) return true;
            }
        }
    }
    return false;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input/data2.txt", "r", stdin);
    string line;
    while ( cin >> line) {
        if( line == "create"){
            string type;
            cin >> type;
            if( type == "RECTANGLE" ){
                string id;
                int x, y;
                int lx, ly;
                char dir;
                int speed;
                cin >> id >> x >> y >> lx >> ly >> dir >> speed;
                Rectangle* rect = new Rectangle(id, x, y, lx, ly, dir, speed);
                if( !checkRecCollides(rect, objList)){
                    objList.push_back( rect);
                }
            }
            else if( type == "CIRCLE" ){
                string id;
                int x, y;
                int r;
                char dir;
                int speed;
                cin >> id >> x >> y >> r >> dir >> speed;
                Circle* cir = new Circle(id, x, y, r, dir, speed);
                if( !checkCirCollides(cir, objList)){
                        objList.push_back(cir);
                }
            }
        }
        else if( line == "move"){
            for(auto obj: objList){
                obj->move();
            }
            checkMap.clear();

            for( auto obj: objList){
                if(checkMap[obj] == false){
                    if( obj->type == "rectangle" ){
                        Rectangle* rect = static_cast<Rectangle*>(obj);
                        if( checkRecCollides(rect, objList)){
                            // cout << "Collider" << obj->id << endl;
                            checkMap[obj] = true;
                        }
                    }
                    else if(obj->type == "circle"){
                        Circle* circle = static_cast<Circle*>(obj);
                        if( checkCirCollides(circle, objList)){
                            // cout << "Collider" << obj->id << endl;
                            checkMap[obj] = true;
                        }
                    }
                }
            }
            for( auto o: checkMap){
                if( o.second == true)
                    (o.first)->remove();
            }
        }
        else if( line == "change_direction"){
            string id;
            char dir;
            int speed;
            cin >> id >> dir >> speed;
            
            for(auto obj: objList){
                if( obj->id == id){
                    // cout << "change" << endl;
                    obj->change(dir, speed);
                    break;
                }
            }
        }
        else if( line == "view_position"){
            string id;
            cin >> id;
            bool chk = false;
            for(auto obj: objList){
                if(obj->id == id) {
                    chk = true;
                    obj->view_position();
                }
            }
            if( !chk ) cout << "NULL" << endl;
        }
        else
            return 0;
    }
    return 0;
}