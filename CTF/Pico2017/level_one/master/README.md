# Lazy Dev

We are given the following site to hack:

![image](https://user-images.githubusercontent.com/24576987/33106054-65f2fbe0-cefe-11e7-81c1-11efe5759a45.png)

Upon looking at its source code, we can figure out that the password is validated using a specific file:
![image](https://user-images.githubusercontent.com/24576987/33106070-7af234c0-cefe-11e7-9574-0452d7042e6f.png)

Interesting, so it looks like `make_ajax_req()` is the function we want to call, but there is apparently no way to access it. I wonder what happens when we try to use the console to call these functions?

![image](https://user-images.githubusercontent.com/24576987/33106149-d19bc598-cefe-11e7-8fe7-c37d69b6430e.png)

So it looks like that's not the right function to call according to this website. What about `make_ajax_req()`?

![image](https://user-images.githubusercontent.com/24576987/33106181-efdc6e90-cefe-11e7-99cb-57e59603cae0.png)

Huh? What gives? Well, apparently `make_ajax_req()` requires an input, but what kind of input cause the program to work?

Take a look at the following code:
`  var params = "pword_valid=" + input.toString(); `
According to this code, the `params` argument will be sent a string version of whatever `input` is. What kind of values would you expect `pword_valid` to have? Perhaps `true` and `false`, correct? Let's try it:

![image](https://user-images.githubusercontent.com/24576987/33106276-60641f78-ceff-11e7-9202-54acfab94b0d.png)

Aha! Onto Level Two!
