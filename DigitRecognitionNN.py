#!/usr/bin/python3



import tensorflow as tf
import pandas as pd

x_train = pd.read_csv('/home/arthik/TENACIOUS/PYTHON/GESTURE_KEYBOARD/x_train.csv')
y_train = pd.read_csv('/home/arthik/TENACIOUS/PYTHON/GESTURE_KEYBOARD/y_train.csv')
x_test = pd.read_csv('/home/arthik/TENACIOUS/PYTHON/GESTURE_KEYBOARD/x_test.csv')
y_test = pd.read_csv('/home/arthik/TENACIOUS/PYTHON/GESTURE_KEYBOARD/y_test.csv')

import matplotlib.pyplot as plt

#Printing the matrix
#print(x_train[0])

#Creating the model
model = tf.keras.models.Sequential()
#model.add(tf.keras.layers.Flatten())
model.add(tf.keras.layers.Dense(10,activation=tf.nn.relu))
model.add(tf.keras.layers.Dense(10,activation=tf.nn.relu))
model.add(tf.keras.layers.Dense(4,activation=tf.nn.softmax))

#Compiling the model
model.compile(optimizer='adam',
	loss='sparse_categorical_crossentropy',
	metrics=['accuracy'])

#Training the model
model.fit(x_train, y_train, epochs=500)

#Calculating loss and the accuracy
val_loss, val_acc = model.evaluate(x_test, y_test)
print('Accuracy : ')
print(val_acc)
print('Loss : ')
print(val_loss)

#Saving the model
import os.path

if os.path.isfile('/home/arthik/TENACIOUS/PYTHON/GESTURE_KEYBOARD/Gesture_Model.h5') is False:
	model.save('/home/arthik/TENACIOUS/PYTHON/GESTURE_KEYBOARD/Gesture_Model.h5')

#Saving Weights
if os.path.isfile('/home/arthik/TENACIOUS/PYTHON/GESTURE_KEYBOARD/Gesture_Weights.h5') is False:
	model.save_weights('/home/arthik/TENACIOUS/PYTHON/GESTURE_KEYBOARD/Gesture_Weights.h5')
