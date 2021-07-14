load DIGITS.csv

load Gesture_Weights.h5

index = input('Enter the index of the data to predict : ')

IN = DIGITS((index),:);

OU = max(0,(max(0,(IN*dense.dense.kernel_0'+dense.dense.bias_0))*dense_1.dense_1.kernel_0'+dense_1.dense_1.bias_0))*dense_2.dense_2.kernel_0'+dense_2.dense_2.bias_0

SOFTMAX = exp(OU-max(OU))./sum(exp(OU-max(OU)))

[num,ind] = max(SOFTMAX);

printf('The predicted Integer is : %d\n',ind-1)
printf('Detected with %f%% confidence.\n',num*100);
