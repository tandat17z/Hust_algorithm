// Segment Tree là một cây. Cụ thể hơn, nó là một cây nhị phân đầy đủ,
// với mỗi nút quản lý một đoạn trên dãy số. 
//
// Với một dãy số gồm N phần tử, nút gốc sẽ lưu thông tin về đoạn [1,N] (giá trị cần tìm trên đoạn đó)
// , nút con trái của nó sẽ lưu thông tin về đoạn [1,⌊N/2⌋]
//  và nút con phải sẽ lưu thông tin về đoạn [⌊N/2⌋+1,N]
// . Tổng quát hơn: nếu nút A lưu thông tin đoạn [i,j]
// , thì 2 con của nó: A1 và A2
//  sẽ lưu thông tin của các đoạn [i,⌊(i+j)/2⌋] và đoạn [⌊(i+j)/2⌋+1,j]
// .