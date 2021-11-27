# Write your MySQL query statement below
#select Department.name as Department, e1.name as Employee, e1.salary as Salary
#from Department inner join Employee as e1
#on Department.id = e1.departmentId
#where (select count(distinct e2.salary)
#      from Employee as e2
#      where e2.salary > e1.salary
#      and e2.departmentId = e1.departmentId) < 3
#;
select Department.name as Department, e2.name as Employee, e2.salary as Salary
from Department inner join (select * from(
    select Employee.*, dense_rank() over (partition by departmentId order by salary desc) as seq
    from Employee
) as e1
where e1.seq <= 3) as e2
on Department.id = e2.departmentId
