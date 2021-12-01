# Write your MySQL query statement below
select c1.name
from (select v2.candidateId
     from (select v1.*, 
                count(*) as c
                #max(count(*) over(partition by v1.candidateId)) over() as maxcount
          from Vote as v1
          group by v1.candidateId
          order by c desc
          limit 1) as v2) as v3 left join Candidate as c1
on v3.candidateId = c1.id
