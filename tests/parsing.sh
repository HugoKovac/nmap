# valgrind --leak-check=full
./ft_nmap --ip
./ft_nmap --ports
./ft_nmap --ports 20
./ft_nmap --ip google.com --ports 20
./ft_nmap --ports 20-90
./ft_nmap --ip google.com --ports 20-90 google.com
./ft_nmap test.com --ports 20-90 google.com