from datetime import datetime, timedelta
seoul_time = datetime.utcnow() + timedelta(hours=9)

print(seoul_time.strftime('%Y-%m-%d'))