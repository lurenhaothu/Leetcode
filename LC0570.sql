# Write your MySQL query statement below
select e1.name
from Employee as e1
where e1.id in (select m1.managerId 
      from (select managerId, count(*)
      from Employee
      group by managerId
      having not managerId is null
      and count(*) >= 5) as m1)
