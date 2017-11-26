# HashChain

We are given the following challenge:

![image](https://user-images.githubusercontent.com/24576987/33237987-de55c284-d250-11e7-8b11-c793921a203a.png)

With this challenge, we are also given the following code:

```python2
    import md5 #Must be run in python 2.7.x

    #code used to calculate successive hashes in a hashchain. 
    seed = "seedhash"

    #this will find the 5th hash in the hashchain. This would be the correct response if prompted with the 6th hash in the hashchain
    hashc = seed
    for _ in xrange(5):
      hashc = md5.new(hashc).hexdigest()
     
    print hashc
```

So, let's see what the actual challenge looked like:

![image](https://user-images.githubusercontent.com/24576987/33237992-1dfd2a1c-d251-11e7-8000-40b03bb5afcc.png)

So this is what it looks like when we register for a new ID. We are given some sort of seed, and to verify that we are implementing the right algorithm, we need to check if we can find the previous hash prior to the given one. But what is a hash first of all, and how do we do these things? Time for a small explanation.

## A Hash Function

For cryptography purposes, a hash function is a mathematical function that translates an input into a theoretically *unique* output. This means that there are *no two inputs should have the same output*—ever. Moreover, the same input should always return the same output.

This is an interesting observation, as it lets us *chain* hashes together to create another unique hash from the results of the previous hash function. A hashchain looks sort of like this:

`h(h(h(h(h(h(x))))))`

What's interesting about a hashchain is that we can theoretically retrace every step of the hash chain if we are given a root—or seed—value to work with, as every input should return a unique output, and that unique output should be the same every single time.

## The challenge

So, combined with our knowledge of hash chains, we should be able to figure out the challenge. In the actual challenge, we are given the hashchain seed (oddly enough) and we are asked to validate this. I've already written up some code to test out this functionality:

```python2
    def generate_hashes(seed):
        a = []
        current_hash = seed
        
        for i in range(1000): 
            current_hash = md5.new(current_hash).hexdigest()
            a.append(current_hash)
        
        return a
```

This simply hashes the results of the previous hash and records the results. To find the previous hash, we simply look up the index of the current hash and subtract by one:

```python2
    def find_prev_hash(array,current_hash):
        return array[array.index(current_hash)-1]
```

Yes, I know that there could be an error depending on how far along the hash was, but I don't really think that PicoCTF would have us hash up to the millions :)

Let's check to see if our program really did work:

![image](https://user-images.githubusercontent.com/24576987/33238056-d172768c-d252-11e7-9606-ae72ad2ba35a.png)

Awesome! So it really did work! Let's see what the flag wants us to do:

![image](https://user-images.githubusercontent.com/24576987/33238062-e947181c-d252-11e7-859b-d0f899de4ffb.png)

Ah, so we need to be able to find some random ID and then compute the previous hash with the ID's seed. I ended up writing a script to automate the process of gathering many, many, many hash IDs and then performing a lookup until I found the answer:

![image](https://user-images.githubusercontent.com/24576987/33238074-27c86e24-d253-11e7-8367-04e596fd5deb.png)

And there's the answer! 90 points for me!
