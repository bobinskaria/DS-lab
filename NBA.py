from sklearn.feature_extraction.text import CountVectorizer
from sklearn.naive_bayes import MultinomialNB

# Training data
messages = [
    "Win a free lottery ticket",
    "Congratulations you won a prize",
    "Claim your free money now",
    "Let's meet for lunch tomorrow",
    "Can you send me the project report",
    "The meeting is scheduled for tomorrow"
]

# Labels: 1 = Spam, 0 = Not Spam
labels = [1, 1, 1, 0, 0, 0]

# Convert text into numerical features
vectorizer = CountVectorizer()
X = vectorizer.fit_transform(messages)

# Create and train the Naive Bayes classifier
model = MultinomialNB()
model.fit(X, labels)

# Test messages
test_messages = [
    "You won free money",
    "Please send the report"
]

# Convert test messages into features
X_test = vectorizer.transform(test_messages)

# Predict
predictions = model.predict(X_test)

# Display results
for message, prediction in zip(test_messages, predictions):
    if prediction == 1:
        print(f'"{message}" -> Spam')
    else:
        print(f'"{message}" -> Not Spam')