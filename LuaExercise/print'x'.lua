--[=[	exercise.lua
--[=[	C���Է���lua����
--]=]
do

	--����ǰ������
	local main


	function main()
		print("Main function head.\n\n")

		print("Please input lines:")
		local lines = io.read("*number")
		local str = ""
		for i = 1,lines*lines,1 do
			local x,y = math.ceil(i/lines), i%lines ~= 0 and i%lines or lines
			if x == y or x+y-1 == lines then
				str = str .. "*"
			else
				str = str .. " "
			end
			if i%lines == 0 then
				str = str .. "\n"
			end
		end
		print("Graphics:\n" .. str .. "End.")

		print("\n\nMain function tail.")
		os.execute("pause")
	end


	--����main����(������)"
	main()

end

