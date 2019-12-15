use QLSV
go

--2.1-	Tạo view V1 cho biết tên khoa có sinh viên có điểm trung bình cao nhất?
create view v1 as
select top 1 a.tenkh, avg(diem) as dtb from khoa a,monhoc b,diem c where a.makh=b.makh and b.mamh=c.mamh
group by a.tenkh
order by dtb desc

select * from v1
--2.2-	Tạo procedure P1 thực hiện các yêu cầu sau : Nhận vào mã khoa và trả về điểm trung bình của sinh viên trong khoa đó, viết đoạn chương trình chạy và hiển thị kết quả trả về.
alter proc p2 @makh varchar(8), @dtb float output
as
	set @dtb=(select avg(diem) from diem a,monhoc b where a.mamh=b.mamh and @makh=makh)

declare @dtb float
exec p2 'vt',@dtb output
print'diem trung binh: '+str(@dtb)
--2.3-	Tạo procedure P2 thực hiện các yêu cầu sau: Nhận vào tên môn học và hiển thị danh sách các sinh viên (mã sv, mã mh, điểm) đã thi đậu môn này (nếu có thi lần 2 và thi đậu thì tính là đã thi đậu).
alter proc p3 @tenmh varchar(40)
as
	select a.masv,b.mamh,a.diem from diem a,monhoc b
	where a.mamh=b.mamh and a.diem >=5 and @tenmh=b.tenmh and lan>=1

exec p3 'tin hoc 01'
--2.4-	Tạo function F1 thực hiện các yêu cầu sau: Nhận vào mã sinh viên và in ra bảng điểm của sinh viên đó gồm (mã sinh viên, mã môn học, điểm). (nếu sinh viên có điểm lần 2 môn đó thì chỉ hiển thị điểm lần 2).
create function f4 ()
--2.5-	Tạo function F2 thực hiện các yêu cầu sau: nhận vào mã khoa, trả về là một table chứa các thông tin (mã sinh viên, tên sinh viên, điểm trung bình) của những sinh viên thuộc khoa truyền vào.
create function f5(@mak char(5))
returns table
as
	return(select d.masv,d.ten,avg(diem) as dtb from diem a,monhoc b, khoa c, sinhvien d
	where a.mamh=b.mamh and b.makh=c.makh and a.masv=d.masv
	group by d.masv,d.ten)

select*from dbo.f5('cntt')