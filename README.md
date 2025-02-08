# CountingCards
## 🔖 Background Information
Let’s pretend that we have an array of elements - they might be integers, characters, or cards in a 52-card playing deck. On this website, Mike Bostock describes three algorithms that can be used to shuffle an array of elements (which can represent cards in a deck) (Bostock, 2012). He claims that the first one is the worst performing algorithm, the second is a small improvement, and the third is the best performer. The third algorithm is known as the Fisher–Yates Algorithm.

Note: technically, the current version of the Fisher-Yates algorithm that we are studying in this lab was an improvement of the original algorithm by Richard Durstenfeld and popularized by Donald E. Knuth (Durstenfeld, 1964). But I guess the original name stuck.

## 🎯 Problem Statement
Test and comment on Mike Bostock’s claim. Do you agree or disagree with his evaluation when you implement the algorithms yourself?

## ✅ Acceptance Criteria
Read through the descriptions of the three algorithms written by Mike Bostock on the website linked above.
Implement the three algorithms listed in his blog post using C++ or Java.
Test the algorithms using whatever means you determine are appropriate. You can determine how many tests are needed, but I do expect to see at least four different sized arrays with four trials each.
Answer the Thought-Provoking Questions using your results. Did your fellow classmates reach the same conclusions?
## 📋 Dev Notes
Note that Mike Bostock wrote the code on his website in Javascript. I don’t expect anyone in this class to know how to write Javascript. But I do think you can piece together the meaning of his code samples by reading and reviewing some documentation.
I would recommend creating a few arrays of differing sizes and running them through the shuffle algorithms for a few trials. A good starting point might be four arrays of different sizes with four trials apiece in each of the three functions (i.e. 4×4×3=48 runs total).
You can use the built-in timing utilities in C++ and Java to do some basic benchmarking of your code.
Automation is your friend. Create some for loops to test all of these cases. Don’t try to do it all by hand 😅
You should turn in your implemented algorithms, just like in any other lab.
## 🖥️ Example Output
There is no specific Example Output for this lab. You are testing three algorithms from somebody’s writing.

## 📝 Thought Provoking Questions
There is only one overarching question this week.

Do you agree with Mike Bostock’s claims that the three algorithms on his site are listed in order of increasing (better) performance?

What evidence do you have to support your claim?
Are there any edge cases that he looked over or missed?
Do you have any comments or recommendations on how to improve performance further?
Etc…
## 💼 Add-Ons For the Portfolio
N/A
