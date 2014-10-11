# demonstrating Document Syntax
learned = <<IDENTIFIER
L    EEEE   A   RRR  N    N
L    E     A A  R  R N N  N
L    EEE  AAAAA RRR  N  N N
L    E    A   A R  R N   N
LLLL EEEE A   A R  R N    N
IDENTIFIER

to = <<IDENTIFIER
TTTTT  OOO
  T   O   O
  T   O   O
  T   O   O
  T    OOO
IDENTIFIER

code = <<IDENTIFIER
 CCC  OOO  DDD  EEEE
C    O   O D  D E
C    O   O D  D EEE
C    O   O D  D E
 CCC  OOO  DDD  EEEE
IDENTIFIER

puts learned + to + code