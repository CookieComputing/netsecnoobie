# My First SQL

We are given the following challenge:

![image](https://user-images.githubusercontent.com/24576987/33190207-29d52fb8-d078-11e7-9357-4ca1c9f1ad73.png)

Let's connect to the website and see what's going on:

![image](https://user-images.githubusercontent.com/24576987/33190216-3d207be0-d078-11e7-8cdd-370a724dcc4f.png)

Ah, so it looks like a standard SQL injection challenge. SQL injection is the act of inputting some malicious text where the server will interpret the input as SQL code, allowing an attacker to perform some nasty stuff on a user's database.

How can we exploit this weakness? Let's try copy and pasting some sql injection code I found online:

![image](https://user-images.githubusercontent.com/24576987/33190298-3bdbf5b0-d079-11e7-90ca-2badb0b36669.png)


Well, that was a failure. An interesting thing to note however, is that we now have access to how the server parses the input:

![image](https://user-images.githubusercontent.com/24576987/33190312-57fee702-d079-11e7-8c7a-0a6895959658.png)

It looks like if we can break the user input and then have the user input return true, we can short circuit the pass query and then gain access into the system.

Let's try the following injection:

`' OR 1=1 --`
Let me explain this attack:

`'` will close up the user query in `user = 'user_input_here'`. This is vital as this means everything we input afterwards will become executable code for SQL.

`OR 1=1` is our true statement that lets us bypass the query. Since `1=1` will always yield true, we can safely bypass the attack

`--` is SQL's way of commenting out the rest of the code. We need to do this or else the rest of the SQL statement can cause some grievances for us.

Let's try running the code and see what happens:

![image](https://user-images.githubusercontent.com/24576987/33190355-de92c1bc-d079-11e7-8de9-8634c8e9950a.png)

Sweet, another 50 points for us!
