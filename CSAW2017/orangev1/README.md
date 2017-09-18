# Orangev1 - CSAW 2017

We were given the following challenge and link:

![image](https://user-images.githubusercontent.com/24576987/30566243-3ce71944-9c99-11e7-8928-7af0773580b7.png)

Upon looking at the web page, we come across this:

![image](https://user-images.githubusercontent.com/24576987/30566270-5a4da2be-9c99-11e7-8dca-1059c12f4c92.png)

After a bit of digging with the path variable, I discovered that it was a directory traversal vulnerability. Let's try going back a folder:

![image](https://user-images.githubusercontent.com/24576987/30566319-8ad5b656-9c99-11e7-9d5a-a3135b91f091.png)

That's interesting, it blocks directory traversal. I tried to look for alternative methods to getting into the parent directory, but my search yielded nothing. I did, however, discover that web browsers will still process URL-encoded data and thus could potentially process the ```..``` command if the developer left out this oversight. Let's try that:

![image](https://user-images.githubusercontent.com/24576987/30566387-dfab9524-9c99-11e7-8b7a-f0f9ed87be23.png)

Nothing? Hmmm... After many tries and difficult googling, I discovered that some applications only check for single encoding, thus allowing double encoding to bypass the filter. Let's try it:

![image](https://user-images.githubusercontent.com/24576987/30566425-036b9a18-9c9a-11e7-8a07-9fae698b3efa.png)

Sweet! That's 100 points for the team.
