import yfinance as yf
import datetime
import matplotlib.pyplot as plt
import seaborn

teststock = yf.Ticker("0050.TW");

hist = teststock.history(period="60d")

#print(hist)

hist.to_csv('TW50.csv')
