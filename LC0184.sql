# Write your MySQL query statement below
select Department.name as Department, Employee.name as Employee, Employee.salary as Salary
from Department inner join Employee
on Department.id = Employee.departmentId
where (Employee.departmentId, Employee.salary) in (
    select departmentId, MAX(salary)
    from Employee
    group by departmentId
)
