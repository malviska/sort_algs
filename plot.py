import pandas as pd
import matplotlib.pyplot as plt
from IPython.display import display

pd.set_option('display.max_columns', None)
pd.set_option('display.max_rows', None)



df = pd.read_csv('./trials/out3.txt')
df1 = df[df['version'] == 1]
df2 = df[df['version'] == 2]
df3 = df[df['version'] == 3]
df4 = df[df['version'] == 4]
df5 = df[df['version'] == 5]
df6 = df[df['version'] == 6]
df7 = df[df['version'] == 7]

for i in [ './trials/out14.txt', './trials/out15.txt', './trials/out65.txt', './trials/out92.txt']:
  df = pd.read_csv(i)
  df1 += df[df['version'] == 1]
  df2 += df[df['version'] == 2]
  df3 += df[df['version'] == 3]
  df4 += df[df['version'] == 4]
  df5 += df[df['version'] == 5]
  df6 += df[df['version'] == 6]
  df7 += df[df['version'] == 7]

df1 = df1.div(5)
df2 = df2.div(5)
df3 = df3.div(5)
df4 = df4.div(5)
df5 = df5.div(5)
df6 = df6.div(5)
df7 = df7.div(5)

df2_3 = df2[df2['k'] == 3]
df2_5 = df2[df2['k'] == 5]
df2_7 = df2[df2['k'] == 7]

df3_10 = df3[df3['m'] == 10]
df3_100 = df3[df3['m'] == 100]
index = 0
indexLabels = 0
parameters = ("totaltime", "comps", "swaps")
labels = ("Tempo Total", "Comparações", "Copias do Registro")
value = (df1,df2_3,df2_5,df2_7,df3_10,df3_100,df4,df5,df6,df7)
methods = ("Quicksort",
 "Quicksort Mediana k = 3",
 "Quicksort Mediana k = 5",
 "Quicksort Mediana k = 7",
 "Quicksort Seleção m = 10",
 "Quicksort Seleção m = 100",
 "Quicksort Pilha",
 "Quicksort Pilha Inteligente",
 "Megesort",
 "Heapsort")

for i in value:
  for x in parameters:
    i.plot(x = 'size', y = x, kind= 'line', title=methods[index], grid = True, label=labels[indexLabels])
    indexLabels += 1
    plt.savefig(methods[index]+'_' + x + '.jpg')
  indexLabels = 0
  index += 1


print("Quicksort:\n")
display(df1.to_string())
print("\n\n")
print("Quicksort Mediana:\n")
display(df2_3.to_string())
display(df2_5.to_string())
display(df2_7.to_string())
print("\n\n")
print("Quicksort Seleção:\n")
display(df3_10.to_string())
display(df3_100.to_string())
print("\n\n")
print("Quicksort Pilha:\n")
display(df4.to_string())
print("\n\n")
print("Quicksort Pilha Inteligente:\n")
display(df5.to_string())
print("\n\n")
print("Mergesort:\n")
display(df6.to_string())
print("\n\n")
print("Heapsort:\n")
display(df7.to_string())
print("\n\n")

