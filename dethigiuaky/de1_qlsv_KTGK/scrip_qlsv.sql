CREATE DATABASE QLSV
go
use QLSV
go
create table khoa(makh varchar(8) primary key, tenkh varchar(40))
create table lop(malop varchar(8)primary key, tenlop varchar(40), makh varchar(8),constraint FK_khoa foreign key(makh) references khoa(makh))
create table sinhvien(masv varchar(8)primary key, ho varchar(40), ten varchar(10),malop varchar(8), phai bit, ngaysinh datetime, noisinh varchar(40), diachi varchar(80), ghichu varchar(8000), nghihoc bit, constraint FK_LOP foreign key (malop)references lop(malop))
create table monhoc(mamh varchar(5) primary key, tenmh varchar(40),makh varchar(8), constraint FK_KHOA1 foreign key (makh)references khoa(makh))
create table diem(masv varchar(8), mamh varchar(5), hocky smallint, lan smallint, diem float, constraint PK_DIEM primary key(masv, mamh,lan), 
constraint FK_SV foreign key (masv) references sinhvien(masv),constraint FK_MH foreign key (mamh) references monhoc(mamh) )
go

use QLSV
go
-- Nhap lieu cho bang Khoa
insert into khoa
values('cntt','cong nghe thong tin')
insert into khoa
values('qtkd','quan tri kinh doanh')
insert into khoa
values('vt','vien thong')

-- Nhap lieu cho bang lop
insert into lop
values('cntt01','Cong nghe thong tin 01','cntt')
insert into lop
values('cntt02','Cong nghe thong tin 02','cntt')
insert into lop
values('qtkd01','quan tri kinh doanh 01','qtkd')
insert into lop
values('qtkd02','quan tri kinh doanh 02','qtkd')
insert into lop
values('vt01','vien thong 01','vt')
insert into lop
values('vt02','vien thong 02','vt')

-- Nhap lieu cho bang sinhvien
insert into sinhvien
values('a001','Le van','a','cntt01',1,'19800101','tphcm','12 le lai','tot',0)
insert into sinhvien
values('a002','Le thi','b','cntt01',0,'19800102','tphcm','13 le lai','tot',0)
insert into sinhvien
values('a003','Le thi','c','cntt01',0,'19800103','tphcm','14 le lai','tot',0)

insert into sinhvien
values('a004','Le van','d','cntt02',1,'19800104','tphcm','15 le lai','tot',0)
insert into sinhvien
values('a005','Le thi','e','cntt02',0,'19800105','tphcm','16 le lai','tot',0)
insert into sinhvien
values('a006','Le thi','f','cntt02',0,'19800106','tphcm','17 le lai','tot',0)

insert into sinhvien
values('b001','Le van','g','qtkd01',1,'19800107','tphcm','12 le lai','tot',0)
insert into sinhvien
values('b002','Le thi','h','qtkd01',0,'19800108','tphcm','13 le lai','tot',0)
insert into sinhvien
values('b003','Le thi','i','qtkd01',0,'19800109','tphcm','14 le lai','tot',0)

insert into sinhvien
values('b004','Le van','j','qtkd02',1,'19800104','tphcm','15 le lai','tot',0)
insert into sinhvien
values('b005','Le thi','k','qtkd02',0,'19800105','tphcm','16 le lai','tot',0)
insert into sinhvien
values('b006','Le thi','l','qtkd02',0,'19800106','tphcm','17 le lai','tot',0)

insert into sinhvien
values('c001','Le van','m','vt01',1,'19800107','tphcm','12 le lai','tot',0)
insert into sinhvien
values('c002','Le thi','n','vt01',0,'19800108','tphcm','13 le lai','tot',0)
insert into sinhvien
values('c003','Le thi','o','vt01',0,'19800109','tphcm','14 le lai','tot',0)

insert into sinhvien
values('c004','Le van','p','vt02',1,'19800104','tphcm','15 le lai','tot',0)
insert into sinhvien
values('c005','Le thi','q','vt02',0,'19800105','tphcm','16 le lai','tot',0)
insert into sinhvien
values('c006','Le thi','r','vt02',0,'19800106','tphcm','17 le lai','tot',0)

--Nhap lieu cho bang monhoc
insert into monhoc
values('th01','tin hoc 01','cntt')
insert into monhoc
values('th02','tin hoc 02','cntt')
insert into monhoc
values('th03','tin hoc 03','cntt')

insert into monhoc
values('kd01','kinh doanh 01','qtkd')
insert into monhoc
values('kd02','kinh doanh 02','qtkd')
insert into monhoc
values('kd03','kinh doanh 03','qtkd')

insert into monhoc
values('vt01','vien thong 01','vt')
insert into monhoc
values('vt02','vien thong 02','vt')
insert into monhoc
values('vt03','vien thong 03','vt')

-- Nhap lieu cho bang diem
insert into diem
values('a001','th01',1,1,8)
insert into diem
values('a001','th02',1,1,4)
insert into diem
values('a001','th02',1,2,9)
insert into diem
values('a002','th01',1,1,8)
insert into diem
values('a002','th02',1,1,7)
insert into diem
values('a002','th03',1,1,6)
insert into diem
values('a003','th01',1,1,4)
insert into diem
values('a003','th01',1,2,7)
insert into diem
values('a003','th02',1,1,8)
insert into diem
values('a003','th03',1,1,5)

insert into diem
values('b001','kd01',1,1,8)
insert into diem
values('b001','kd02',1,1,4)
insert into diem
values('b001','kd02',1,2,9)
insert into diem
values('b002','kd01',1,1,8)
insert into diem
values('b002','kd02',1,1,7)
insert into diem
values('b002','kd03',1,1,6)
insert into diem
values('b003','kd01',1,1,4)
insert into diem
values('b003','kd01',1,2,7)
insert into diem
values('b003','kd02',1,1,8)
insert into diem
values('b003','kd03',1,1,5)

insert into diem
values('c001','vt01',1,1,8)
insert into diem
values('c001','vt02',1,1,4)
insert into diem
values('c001','vt02',1,2,3)
insert into diem
values('c002','vt01',1,1,8)
insert into diem
values('c002','vt02',1,1,7)
insert into diem
values('c002','vt03',1,1,6)
insert into diem
values('c003','vt01',1,1,4)
insert into diem
values('c003','vt01',1,2,7)
insert into diem
values('c003','vt02',1,1,2)
insert into diem
values('c003','vt03',1,1,5)

