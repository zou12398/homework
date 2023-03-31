create database test;
use test;
create table user(
    id int,
    username varchar(20),
    password varchar(50)
);

insert into user(username, password) values ('zhangsan','123'),('lisi','321');