select a2.player_id, min(a2.event_date) as first_login
from Activity as a2
group by a2.player_id
