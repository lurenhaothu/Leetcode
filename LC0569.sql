# Write your MySQL query statement below
select e2.id, e2.company, e2.salary
from (select e1.*, row_number() over(partition by company order by salary) as r,
      count(*) over(partition by company) as c
      from Employee as e1) as e2
where e2.r between e2.c / 2 and e2.c / 2 + 1

