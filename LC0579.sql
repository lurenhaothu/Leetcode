# Write your MySQL query statement below
select e4.id, e4.month, e4.cumuSalary as Salary
from (select e1.*, 
        e1.salary + 
        if(e2.salary is null, 0, e2.salary) + 
        if(e3.salary is null, 0, e3.salary) as cumuSalary,
        max(e1.month) over(partition by e1.id) as maxmonth
    from Employee e1 
    left join Employee e2
    on e1.id = e2.id
    and e1.month = e2.month + 1
    left join Employee e3
    on e1.id = e3.id
    and e1.month = e3.month + 2) as e4
where e4.month != e4.maxmonth
order by e4.id, e4.month desc
