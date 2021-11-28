# Write your MySQL query statement below
select a3.player_id, a3.device_id
from Activity as a3
where (a3.player_id, a3.event_date) in (
    select a2.player_id, min(a2.event_date) as first_login
    from Activity as a2
    group by a2.player_id)
