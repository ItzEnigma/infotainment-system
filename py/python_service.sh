[Unit]
Description=Run Bash Script Service

[Service]
Type=simple
ExecStart=/usr/bin/python3 /home/weston/start.py
WorkingDirectory=/home/weston
Restart=always

[Install]
WantedBy=multi-user.target
