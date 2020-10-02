while 1:
    w=float(input())
    if w<0:break
    print("Objects weighing {:.2f} on Earth will weigh {:.2f} on the moon.".format(w,w*(.167)))