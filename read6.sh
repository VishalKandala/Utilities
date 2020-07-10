ml load matplotlib
awk '/relative/{print $3,$6,$13,$NF}' $(ls | grep "output")>data.txt
python plot6.py
