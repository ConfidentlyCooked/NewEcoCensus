from PIL import Image
<<<<<<< HEAD
import get_lat_lon_exif_pil as gll
=======
#import get_lat_lon_exif_pil as gll
>>>>>>> Cleaned repository
import utm
import os, sys
import cv2
import numpy as np
import struct
import scipy
<<<<<<< HEAD
import scipy.misc
import scipy.cluster
=======
from PIL.ExifTags import TAGS, GPSTAGS

def get_exif_data(image):
    """Returns a dictionary from the exif data of an PIL Image item. Also converts the GPS Tags"""
    exif_data = {}
    info = image._getexif()
    if info:
        for tag, value in info.items():
            decoded = TAGS.get(tag, tag)
            if decoded == "GPSInfo":
                gps_data = {}
                for t in value:
                    sub_decoded = GPSTAGS.get(t, t)
                    gps_data[sub_decoded] = value[t]
                    #print t, sub_decoded, value[t]
                exif_data[decoded] = gps_data
            else:
                exif_data[decoded] = value

    return exif_data


def _get_if_exist(data, key):
    if key in data:
        return data[key]

    return None


def _convert_to_degress(value):
    """Helper function to convert the GPS coordinates stored in the EXIF to degress in float format"""
    d0 = value[0][0]
    d1 = value[0][1]
    d = float(d0) / float(d1)

    m0 = value[1][0]
    m1 = value[1][1]
    m = float(m0) / float(m1)

    s0 = value[2][0]
    s1 = value[2][1]
    s = float(s0) / float(s1)

    return d + (m / 60.0) + (s / 3600.0)


def get_lat_lon(exif_data):
    """Returns the latitude and longitude, if available, from the provided exif_data (obtained through get_exif_data above)"""
    dir = None
    lat = None
    lon = None

    if "GPSInfo" in exif_data:
        gps_info = exif_data["GPSInfo"]

        gps_direction = _get_if_exist(gps_info, 'GPSImgDirection')
        gps_direction_ref = _get_if_exist(gps_info, 'GPSImgDirectionRef')
        gps_latitude = _get_if_exist(gps_info, "GPSLatitude")
        gps_latitude_ref = _get_if_exist(gps_info, 'GPSLatitudeRef')
        gps_longitude = _get_if_exist(gps_info, 'GPSLongitude')
        gps_longitude_ref = _get_if_exist(gps_info, 'GPSLongitudeRef')

        #print gps_direction, gps_direction_ref
        #print gps_latitude, gps_latitude_ref
        #print gps_longitude, gps_longitude_ref
        if gps_latitude and gps_latitude_ref and gps_longitude and gps_longitude_ref:
            if gps_direction_ref and gps_direction:
                dir = _convert_to_degress(gps_direction)
                if gps_direction_ref != "N":
                    dir = 0 - dir
            else:
                dir = None

            lat = _convert_to_degress(gps_latitude)
            if gps_latitude_ref != "N":
                lat = 0 - lat

            lon = _convert_to_degress(gps_longitude)
            if gps_longitude_ref != "E":
                lon = 0 - lon


    return dir, lat, lon
>>>>>>> Cleaned repository

def main():
    rootdir = sys.argv[1] + '/' #'/Users/bound_to_love/Downloads/Test02142018'
    directory = os.path.dirname(sys.argv[2] + '/Partitions/') #/Users/bound_to_love/Downloads/Test02142018/Partitions/')
    f = open(str(sys.argv[2]) + "/Drone_coords.txt", "w+")
    if os.path.exists(directory):
        print "Directory already exists"

    if not os.path.exists(directory):
        os.makedirs(directory)
        print "Directory made for partitions"

    files = os.listdir(rootdir)
    for file in files:
        if ".JPG" in file:
            image = Image.open(str(rootdir + '/' + file))
<<<<<<< HEAD
            exif_data = gll.get_exif_data(image)
            dir, lat, lon = gll.get_lat_lon(exif_data)
=======
            exif_data = get_exif_data(image)
            dir, lat, lon = get_lat_lon(exif_data)
>>>>>>> Cleaned repository
            f.write((file + " " + str(dir) + " "+ str(lat) + " " + str(lon) + " " + str(image.size[0]) + " " + str(image.size[1])) + str("\n"))
            imgPartition = cv2.imread(rootdir + "/" + file)
            x, y, c = imgPartition.shape
            xp = len(str(x))
            yp = len(str(y))
            i, j = 0, 0
            #while i < (x/10)*10:
                #while j < (y/10)*10:
                    #partition = imgPartition.crop((i, j, (i + x / 10), (j + y / 10)))
            while i < x:
                i2 = i + 300
                while j < y:
                    j2 = j + 300
                    newfile = directory + "/" + str(j).zfill(yp) + "_" + str(i).zfill(xp) + "_" + file
                    partition = imgPartition[i:i2, j:j2]#cv2.resize(imgPartition[i:i2, j:j2],(x, y), interpolation = cv2.INTER_LINEAR)
                    cv2.imwrite(newfile, partition)
                    #j += y / 10
                    j += 300
                #i += x / 10
                i += 300
                j = 0
    f.close()

if __name__ == "__main__":
    main()
