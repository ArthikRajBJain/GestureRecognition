#!/usr/bin/python3


import tensorflow as tf 
from tensorflow.keras.models import load_model
import matplotlib.pyplot as plt 
import numpy as np

mnist = tf.keras.datasets.mnist #28x28 image of digits

(x_train, y_train), (x_test, y_test) = mnist.load_data('mnist.npz')

#Normalizing the data
x_train = tf.keras.utils.normalize(x_train, axis=1)
x_test = tf.keras.utils.normalize(x_test, axis=1)


#Import the model
new_model = load_model('/home/arthik/TENACIOUS/PYTHON/PYTHON/KERAS/SAVED_MODELS/DigitRecognitionNN/DigitRecognitionNN.h5')

#Showing the model summary
new_model.summary()

#Look at the weights
print('Printing the weights : ')
print(new_model.get_weights())

#Predicting based on the trained model
prediction = new_model.predict([x_test])

val='1'
while(val=='1'):
	index = input('Enter the index of the data to predict : ')
	index=int(index)
	print("\nRAW Prediction Data : ")
	print(prediction[index])
	print('Compiled Prediction Data ')
	print(np.argmax(prediction[index]))


	#Showing the image
	plt.imshow(x_test[index], cmap = plt.cm.binary)
	plt.show()
	val = input('Do you want to run again Y/N(1/0) : ')