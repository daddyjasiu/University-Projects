# RPN <=> INF both ways conversion.

Program deletes unwanted signs such as `","`, `"spaces"` etc. and checks syntax of given input expression.

Then, it converts RPN expression to INF form, or INF expression to RPN form.

First input variable is how many data sets user will put in. Then, program awaits for determining which notation do you want to convert,
RPN or INF. After that user is supposed to type in the expression. Program outputs expression converted to wanted notation form.

Program uses stack to solve the conversion problem. Example input/output below. Note, that RPN in Polish is ONP, hence different spelling in i/o.


### INPUT:
```26
INF: a)+(b
ONP: ab+a~a-+
INF: a+b+(~a-a)
INF: x=~~a+b*c
INF: t=~a<x<~b
INF: ~a-~~b<c+d&!p|!!q
INF: a^b*c-d<xp|q+x
INF: x=~a*b/c-d+e%~f
ONP: xabcdefg++++++=
ONP: ab+c+d+e+f+g+
ONP: abc++def++g++
ONP: abc++def++g+++
INF: x=a=b=c
ONP: xabc===
INF: x=a^b^c
INF: x=a=b=c^d^e
ONP: xabcde^^===
INF: x=(a=(b=c^(d^e)))
ONP: xa~~~~~~=
INF: x=~~~~a
INF: x=~(~(~(~a)))
ONP: xa~~~~=
INF: x=a+(b-c+d)
ONP: xabc-d++=
INF: x=a+(((a-b)+c))
ONP: xaab-c++=
```

### OUTPUT:
```
INF: a+b+(~a-a)
ONP: ab+a~a-+
ONP: xa~~bc*+=
ONP: ta~x<b~<=
ONP: error
ONP: error
ONP: xa~b*c/d-ef~%+=
INF: x=a+(b+(c+(d+(e+(f+g)))))
INF: a+b+c+d+e+f+g
INF: a+(b+c)+(d+(e+f)+g)
INF: error
ONP: xabc===
INF: x=a=b=c
ONP: xabc^^=
ONP: xabcde^^===
INF: x=a=b=c^d^e
ONP: xabcde^^===
INF: x=~~~~~~a
ONP: xa~~~~=
ONP: xa~~~~=
INF: x=~~~~a
ONP: xabc-d++=
INF: x=a+(b-c+d)
ONP: xaab-c++=
INF: x=a+(a-b+c)
```
