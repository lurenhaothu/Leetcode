# Write your MySQL query statement below
select round(sum(if(a3.player_id is null, 0, 1)) / count(distinct a2.player_id), 2) as fraction
from (select a1.player_id, min(a1.event_date) as f
      from activity as a1
     group by a1.player_id) as a2 left join activity as a3
     on datediff(a3.event_date, a2.f) = 1
     and a3.player_id = a2.player_id
