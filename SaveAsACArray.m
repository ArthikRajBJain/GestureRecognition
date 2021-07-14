file = fopen("CArrays.txt","w");

load Gesture_Weights.h5

d0kernal_0 = dense.dense.kernel_0';
d0bias_0 = dense.dense.bias_0;
d1kernal_0 = dense_1.dense_1.kernel_0';
d1bias_0 = dense_1.dense_1.bias_0;
d2kernal_0 = dense_2.dense_2.kernel_0';
d2bias_0 = dense_2.dense_2.bias_0;

as=["d0kernal_0"; "d0bias_0"; "d1kernal_0"; "d1bias_0"; "d2kernal_0"; "d2bias_0"]
for var = 1:6
	eval(['a = ', as(var,:), ';'])
	fprintf(file,"float %s[%d][%d] = { ", as(var,:), size(a,1), size(a,2))
	for i = 1:size(a,1)
		for j = 1:size(a,2)
			if(i==size(a,1) && j==size(a,2))
				fprintf(file, "%f };\n", a(i,j))
			else
				fprintf(file, "%f, ", a(i,j));
			end
		end
	end
end


fclose(file)
