import matplotlib.pyplot as plt
languages = ['java','python','PHP','JavaScript','C#','C++']
popularity = [22.2,17.6,8.8,8,7.7,6.7]
plt.bar(languages,popularity)
plt.xlabel(' programming Languages')
plt.ylabel('popularity')
plt.title('popularity of Programming Languages')
plt.show()