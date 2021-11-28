# Write your MySQL query statement below
select t3.request_at as Day, round(sum(if(t3.status = 'completed', 0, 1)) / count(*), 2) as `Cancellation Rate`
from (select t2.*
    from (select t1.*
        from Trips as t1 left join Users as u1
        on t1.driver_id = u1.users_id
        where u1.banned != 'Yes') as t2 left join Users as u2
    on t2.client_id = u2.users_id
    where u2.banned != 'Yes') as t3
where t3.request_at between '2013-10-01' and '2013-10-03'
group by t3.request_at
