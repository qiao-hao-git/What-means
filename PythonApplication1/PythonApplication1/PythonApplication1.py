import cv2
import socket
def getHostInfo():
    hostname = socket.gethostname()
    print(hostname)
    ip = socket.gethostbyname(hostname)
    print(ip)
    return  (hostname,ip)
getHostInfo()

def getDeviceNum():
    i = 0
    while(1):
        cam = cv2.VideoCapture(i)
        grabbed = cam.grab()
        cam.release()
        if not grabbed:
            print(i)
            return  
        i += 1
def captureImg(filename):
    try:
        hostname,ip,usr,pw = getHostInfo()
        ur1 = r"rtsp://{0}:{1}@{2}/".format(usr,pw,ip)
        cam = cv2.VideoCapture(ur1)
    except:
        print("请连接摄像头")
        return
    sucess,img = cam.read()
    if(sucess):
        cv2.namedWindow('image',cv2.WINDOW_NORMAL)
        cv2.imshow('image',img)
        cv2.imwrite(filename,img)
        cam.release()
        cv2.waitKey(0)
        cv2.destoryAllWindows()
fname = 'd:\\picl.jpg'
captureImg(fname)



