sleep 5s
ml load matplotlib
awk '/relative/{print $3,$6,$NF,$13}' $(ls | grep "output")>data.txt
python plot6.py
