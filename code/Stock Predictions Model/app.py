import numpy as np
import pandas as pd
import yfinance as yf
from keras.models import load_model
import streamlit as st

model = load_model('D:\stock_Price\Stock Predictions Model.keras')

st.header('Stock Market Predictor')
stock = st.text_input('Enter Stock Symbol','GOOG')
start ='2012-01-01'
end='2022-12-31'
data= yf.download(stock, start,end)
st.subheader('Stock Data')
st.write(data)

data_train= pd.DataFrame(data.Close[0:int(len(data)*0.80)])
data_test= pd.DataFrame(data.Close[int(len(data)*0.80):len(data)])

from sklearn.preprocessing import MinMaxScaler
scaler = MinMaxScaler(feature_range=(0,1))

pas_100_days= data_train.tail(100)
data.test=pd.concat([pas_100_days,data_train],ignore_index=True)
data_test_scale=scaler.fit_transform(data_test)

x=[]
y=[]
for i in range(100,data_test_scale.shape[0]):
  x.append(data_test_scale[i-100:i])
  y.append(data_test_scale[i,0])

  x,y=np.array(x), np.array(y)
  predict= predict *scaler
  scale=1/scaler.scale_  #yeh line humesha kho jata ha
  y=y*scale

st.subheader('Original Price vs  Predicted Price')
fig4 = plt.figure(figsize=(8,6))
plt.plot(predict,'r',label='Original Price')
plt.plot(y,'g',label='Predicted Price')
plt.xlabel('Time')
plt.ylabel('Price')
plt.show()
st.pyplot(fig4)