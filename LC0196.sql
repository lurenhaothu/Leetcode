# Write your MySQL query statement below
delete from Person
where id in (select p3.id from(
select distinct p1.id
from Person as p1, Person as p2
where p1.email = p2.email
and p1.id > p2.id) as p3)
