--[=[	exercise.lua
--[=[	C���Է���lua����
--]=]
do

	--����ǰ������
	local main

	i = 0
	function test()
		return function() return i end
	end
	i = 10
	foo = test()
	print(foo())

	function main()
		print("Main function head.\n\n")

		local num,counter = io.read("*num"),0
		for zeroNum in function(status,var)
							local temp = math.floor(var/5)
							if temp > 0 then
								return temp
							else
								return nil
							end
						end,nil,num
		do
			counter = counter + zeroNum
		end
		print(counter)

		print("\n\nMain function tail.")
		os.execute("pause")
	end


	--����main����(������)"
	main()

end

