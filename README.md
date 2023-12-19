# PROJECT 1
## Sinh viên thực hiện: Nguyễn Thu Hà
## MSSV:20210299
## Giảng viên: Ths.Nguyễn Đức Tiến

### Mô tả yêu cầu đề bài thực hành giai đoạn 1 - tuần 6,7,8
### Tuần 6
1. Cho đồ thị có hướng G = (V, E) trong đó V = {1, 2, ..., n} là tập hợp các nút và w(u,v) là trọng số (độ dài) của cung (u ,v). Tính d(u,v) là độ dài đường đi ngắn nhất từ u đến v trong G với mọi u,v trong V.
2. Cho mạng G = (V, E) là đồ thị có trọng số có hướng. Nút s là nguồn và nút t là đích. c(u,v) là dung lượng của cung (u,v). Tìm luồng cực đại trên G.
3. Cho đồ thị có hướng G = (V,E) trong đó V = {1,2,...,n} là tập hợp các nút. Mỗi cung (u,v) có trọng số không âm w(u,v). Cho hai nút s và t của G. Tìm đường đi ngắn nhất từ s đến t trên G.

### Tuần 7
1. Dữ liệu về doanh số bán hàng của một công ty thương mại điện tử (công ty thương mại điện tử có nhiều cửa hàng) gồm một dãy các dòng, mỗi dòng (đại diện cho một đơn hàng) có các thông tin sau: ID khách hàng, ID sản phẩm, Giá, ID cửa hàng, thời gian.
Thực hiện một chuỗi các truy vấn thuộc các loại sau:
    - ?total_number_orders: trả về tổng số đơn hàng
    - ?total_revenue: trả về tổng doanh thu mà công ty thương mại điện tử nhận được
    - ?revenue_of_shop (ShopID): trả lại tổng doanh thu mà shop (ShopID) nhận được
    - ?total_consume_of_customer_shop (CustomerID) (ShopID): trả về tổng doanh thu shop (ShopID) bán sản phẩm cho khách hàng (CustomerID)
    - ?total_revenue_in_ Period (from_time) (to_time): trả về tổng doanh thu mà thương mại điện tử nhận được trong khoảng thời gian từ (from_time) đến (to_time).
2. Dữ liệu về giao dịch ngân hàng bao gồm một chuỗi các giao dịch: thông tin của từng giao dịch có định dạng sau: \<from_account>\<to_account>\<money>\<time_point>\<atm>. Một chu kỳ giao dịch có độ dài k bắt đầu từ tài khoản a1 được xác định là một chuỗi các tài khoản riêng biệt a1, a2, …, ak trong đó có các giao dịch từ tài khoản a1 đến a2, từ a2 đến a3, …, từ ak đến a1.
Viết chương trình xử lý các truy vấn sau:
    - ?number_transactions: tính tổng số giao dịch của dữ liệu
    - ?total_money_transaction: tính tổng số tiền giao dịch
    - ?list_sorted_accounts: tính toán trình tự tài khoản ngân hàng (bao gồm tài khoản gửi và tài khoản nhận) xuất hiện trong giao dịch (sắp xếp theo thứ tự tăng dần theo bảng chữ cái)
    - ?total_money_transaction_from <tài khoản>: tính tổng số tiền được chuyển từ tài khoản <tài khoản>
    - ?inspect_cycle \<account> k : trả về 1 nếu có chu kỳ giao dịch có độ dài k bắt đầu từ \<account>, ngược lại trả về 0.

### Tuần 8
1. Dữ liệu gửi dự thi lập trình bao gồm một dãy các dòng, mỗi dòng có các thông tin sau: \<UserID>\<ProblemID>\<TimePoint>\<Status>\<Point> trong đó người dùng \<UserID> gửi mã của mình để giải quyết vấn đề \<ProblemID> tại thời điểm \<TimePoint> và nhận trạng thái \<Status> và điểm \<Point>. Người dùng có thể gửi mã để giải quyết từng vấn đề nhiều lần. Điểm mà người dùng nhận được cho một bài toán là điểm tối đa trong số các bài gửi cho bài toán đó. 
Thực hiện một chuỗi các truy vấn thuộc các loại sau:
    - ?total_number_submissions: trả về số lượng bài dự thi
    - ?number_error_submision: trả về số lượng bài gửi có trạng thái ERR
    - ?number_error_submision_of_user \<UserID>: trả về số lần gửi có trạng thái ERR của người dùng \<UserID>
    - ?total_point_of_user \<UserID>: trả về tổng điểm của người dùng \<UserID>
    - ?number_submission_ Period \<from_time_point>\<to_time_point>: trả về số lần gửi trong khoảng thời gian từ <from_time_point> đến <to_time_point>.

2. Cho một DataBase về công dân, thực hiện các truy vấn trên DataBase này. DataBase về công dân gồm các dòng, mỗi dòng là thông tin về một người và có dạng: \<code> <date_of_birth> <father_code> <mother_code> <is_alive> <mã vùng> trong đó
    - \<code>: mã định danh
    - <date_of_birth>: ngày sinh của người đó 
    - <father_code> và <mother_code>: mã của bố và mẹ là những chuỗi có độ dài 7 nếu mã là 0000000 thì người hiện tại không có thông tin về bố hoặc mẹ
    - <is_alive>: ‘Y’ nghĩa là người đó vẫn còn sống và ‘N’ nghĩa là người hiện tại đã chết
    - <zone_code>: mã vùng nơi người đó sinh sống. 
Danh sách các truy vấn bao gồm các lệnh sau:
    - NUMBER_PEOPLE: trả về số lượng người 
    - NUMBER_PEOPLE_BORN_AT \<date>: trả về số người có ngày sinh bằng \<date>
    - MOST_ALIVE_ANCESTOR \<code>: tìm tổ tiên cao nhất (xa nhất về khoảng cách thế hệ) của người \<code> nhất định. Trả về khoảng cách thế hệ giữa tổ tiên được tìm thấy và người đã cho
    - NUMBER_PEOPLE_BORN_BETWEEN <from_date> <to_date>: tính số người có ngày sinh trong khoảng từ <from_date> đến <to_date>
    - MAX_UNRELATED_PEOPLE: tìm một tập con gồm những người trong đó có hai người bất kỳ trong tập con đó không có cha/mẹ-con và kích thước của tập con đó là lớn nhất. Trả về kích thước của tập hợp con được tìm thấy.
