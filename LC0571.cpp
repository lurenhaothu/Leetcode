# Write your MySQL query statement below
select avg(n2.num) as median
from (select n.*, 
        sum(n.frequency) over() as sumall, 
        sum(n.frequency) over(order by n.num) as sumwindow,
        sum(n.frequency) over(order by n.num) - n.frequency + 1 as sumbottom
      from Numbers as n) as n2
where ceiling(n2.sumall / 2) between n2.sumbottom and n2.sumwindow
or floor(n2.sumall / 2 + 1) between n2.sumbottom and n2.sumwindow
