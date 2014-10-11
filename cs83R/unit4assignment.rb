print "\nCorsair Fare Calculator\n"

print "Enter the distance traveled: "
miles = gets.chomp.to_i
print "Enter number of checked bags: "
numbags = gets.chomp.to_i
print "Enter number of meals ordered: "
nummeals = gets.chomp.to_i
print "Roundtrip desired? [1=yes/0=no]: "
roundtrip = gets.chomp.to_i
print "Is there a Saturday night stayover? [1=yes/0=no]: "
stayover = gets.chomp.to_i
print "SMC Student traveler? [1=yes/0=no]: "
student = gets.chomp.to_i

distance = miles * 0.15
bagrate = numbags * 25
mealrate = nummeals * 10
discount = 0


fare = (distance + bagrate + mealrate)

if (roundtrip == 1)
	roundtripRate = 0.05
	roundtripDiscount = (fare * roundtripRate)
	discount += roundtripDiscount
else
	# no discount
end

if (roundtrip == 1 and stayover == 1)
	discount += 50
else
	# no discount
end

if (student == 1)
	discount += bagrate
else
	# no discount
end 

total = fare - discount

fare = '%.2f' % fare
discount = '%.2f' % discount
total = '%.2f' % total

print "Fare: $ #{fare}\n"
print "Reductions: $ #{discount}\n"
print "Total Cost: $ #{total}\n"

print "\nContinue (y/n)? "
continue = gets.chomp

if (continue == 'y')
	exec "ruby unit4assignment.rb"
elsif (continue == 'n')
	print "Bye, bye!"
else
	print "Please type 'y' or 'n' to continue."
end
	