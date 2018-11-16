from PIL import Image
import os, sys
import math

DEBUG = 0

partsize = 300

args = sys.argv
alen = len(args)
if DEBUG >= 2:
    print args
if alen >= 1:
    script = args[0]

if alen >= 2:
    root = args[1]
else:
    if DEBUG >= 1:
        print("error about args root")

if alen >= 3:
    dest = args[2]
else:
    if DEBUG >= 1:
        print("error about args dest")

if DEBUG >= 2:
    print script, root, dest

if os.path.isdir(dest):
    if DEBUG >= 1:
        print "Destination exists, creating partitions"
else:
    if DEBUG >= 1:
        print "Destination does not exist, making it"
    os.mkdir(dest)

os.chdir(root)
files = os.listdir("./")
if DEBUG >= 2:
    print "Files:", files
for f in files:
    if f[-4:] == ".jpg" or f[-5] == ".jpeg":
        if DEBUG >= 1:
            print "Partitioning file", f
        cimg = "no image"
        try:
            cimg = Image.open(f, mode='r')
        except IOError:
            if DEBUG >= 1:
                print "file", path, "unable to open for partitioning"
        if cimg == "no image":
            continue
        w, h = cimg.size
        pad = 0
        if w >= h:
            pad = len(str(w))
        else:
            pad = len(str(h))
        numx = int(math.ceil(w / float(partsize)))
        numy = int(math.ceil(h / float(partsize)))
        if DEBUG >= 2:
            print "Image Size:", w, h, "Partitions:", numx, numy
        
        y = 0
        while (y < numy):
            x = 0
            while (x < numx):
                rx = x * partsize
                ry = y * partsize
                rw = rx + partsize
                if rw > w:
                    rw = w
                rh = ry + partsize
                if rh > h:
                    rh = h
                frag = cimg.crop((rx, ry, rw, rh))
                nw, nh = frag.size
                if nw <= 0 or nh <= 0:
                    if DEBUG >= 3:
                        print "Image evenly divisible, skipping fragment", x, y
                else:
                    path = dest
                    nx = str(rx).zfill(pad)
                    ny = str(ry).zfill(pad)
                    name = f
                    if DEBUG >= 4:
                        print "saving", dest, nx, ny, name
                    frag.save(os.path.join(path, nx + "_" + ny + "_" + f))
                x += 1
            # x loop end
            y += 1
        #y loop end
