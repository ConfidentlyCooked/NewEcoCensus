"""
Image Reader
Copyright 2017: Morgan West, Rebekah Loving
"""

# TODO: Find a library to read in metadata/exifdata that puts the data in a usable format.
#   ExifRead puts the data into an unusable format that cannot be changed or manipulated and can
#   only be printed.
import os, sys
<<<<<<< HEAD
import coordFinder as crdfdr # class to calculate coordinates of selected plants in images
import fnmatch
=======
#import coordFinder as crdfdr # class to calculate coordinates of selected plants in images
import fnmatch

"""
EcoCensus Coordinate converter
Copyright 2017: Morgan West, Rebekah Loving, Morgan Friend
"""

import math
import utm

# This class will take the x,y coordinates of fauna found in a given
# image and output the real world coordinates.
# This class will be called per image list with identical non-metadata variables eg FOV, direciton.
# For example:
"""
find = coordFinder(94,0)
for droneCoords,droneHeight,focalLength,plantCoords in classifiedImages:
    classifiedCoordinateList.append(find.processCoords(droneCoords,droneHeight,focalLength,plantCoords))
"""

class CoordFinder:

    # if there is no defined direction, pass direction as 0 to assume north-up orientation
    def __init__(self,FOV,height):
        self.theta = float(FOV / 2)
        self.droneHeight = height # in meters
        return

    # Converts coordinates from geographic to decimal degrees
    # Used because coordinates stored in image metadata are in geographic form
    def toDecimalDegrees(self,droneCoords):
        # Type checking
        tupleType = type((0,0))
        floatType = type(1.1)
        if (type(droneCoords) != tupleType):
            return
        if (len(droneCoords) != 2):
            return
        if (type(droneCoords[0]) != floatType or type(droneCoords[1]) != floatType):
            return

        # Geographic coords stored as tuple of lists ([hours,minutes,seconds],[hours,minutes,seconds])
        # Conversion formula is (hr + (min/60) + (sec/3600))
        latitude = droneCoords[0]
        longitude = droneCoords[1]
        newLatitude = float(latitude[0] + float(latitude[1] / 60) + float(latitude[2] / 3600))
        newLongitude = float(longitude[0] + float(longitude[1] / 60) + float(longitude[2] / 3600))
        return (newLatitude,newLongitude)

    # Converts decimal degrees to universal transverse mercador in zone 5Q (Big Island).
    # Returns a coordinate tuple in UTM.
    def toUTM(self,coords):
        # Type checking
        tupleType = type((0,0))
        floatType = type(1.1)
        if (type(coords) != tupleType):
            return
        if (len(coords) != 2):
            return
        if (type(coords[0]) != floatType or type(coords[1]) != floatType):
            return

        # Conversion
        latitude = coords[0]
        longitude = coords[1]
        return utm.from_latlon(latitude,longitude) # see documentation for utm library

    # Takes in UTM coordinates and outputs decimal degree coordinates
    def fromUTM(self,coords):
        # Type checking
        tupleType = type((0,0))
        floatType = type(1.1)
        if (type(coords) != tupleType):
            return
        if (len(coords) != 2):
            return
        if (type(coords[0]) != floatType or type(coords[1]) != floatType):
            return

        # Conversion
        return utm.to_latlon(coords)

    # Takes the coordinate given from the image data and calculates the edge
    def getEdges(self,droneDD,imageRatio):
        # Type checking
        tupleType = type((0,0))
        floatType = type(1.1)
        intType = type(1)
        if (type(droneDD) != tupleType):
            return
        if (len(droneDD) != 2):
            return
        if (type(droneDD[0]) != floatType or type(droneDD[1]) != floatType):
            return

        # defining and setting variables
        droneLat = droneDD[0]
        droneLong = droneDD[1]
        edges = [] # list of edges [top, right, bottom, left]
        distToEdge = float(self.droneHeight*math.tan(self.theta))

        # conversion from meters to decimal degrees
        # 1 m = 0.0004858 dd
        distToEdge = float(distToEdge * 0.0004858)

        # edge calculations assuming orientation is north-up
        NSdistToEdge = float(distToEdge * imageRatio) # since the image is wider than it is tall
        northx = droneLat
        northy = droneLong + NSdistToEdge
        westx = droneLat + distToEdge
        westy = droneLong
        southx = droneLat
        southy = droneLong - NSdistToEdge
        eastx = droneLat - distToEdge
        easty = droneLong

        # add coordinates to list in NESW order
        edges.append((northx,northy))   # N
        edges.append((westx,westy))     # E
        edges.append((southx,southy))   # S
        edges.append((eastx,easty))     # W
        return edges

    # Finds the midpoint of the coordinates calculated for multiple images that contain the same
    #   geographic location.
    def midpoint(self,coordinates):
        # Type checking
##        tupleType = type((0,0))
##        floatType = type(1.1)
##        if (type(coordinates) != tupleType):
##            return
##        if (len(coordinates) != 2):
##            return
##        if (type(coordinates[0]) != floatType or type(coordinates[1]) != floatType):
##            return

        # Midpoint calculation
        xsum = 0
        ysum = 0
        for coord in coordinates:
            xsum += coord[0]
            ysum += coord[1]
        xcoord = xsum / len(coordinates)
        ycoord = ysum / len(coordinates)
        return (xcoord,ycoord)

    # Rotates the coordinate around the origin (droneCoords) of the image to match direcitonal rotation
    #       of the drone.
    def rotate(self, coords, origin, direction):

        # Type checking
##        tupleType = type((0,0))
##        floatType = type(1.1)
##        intType = type(1)
##        if (type(coords) != tupleType):
##            return
##        if (len(coords) != 2):
##            return
##        if (type(coords[0]) != floatType or type(coords[1]) != floatType):
##            return
##        if (type(origin) != tupleType):
##            return
##        if (len(origin) != 2):
##            return

        # change image coordinates to emulate the center of the image as (0,0)
        xcoord = float(coords[0] - origin[0])
        ycoord = float(coords[1] - origin[1])

        # rotate coordinates around new origin
        # x' = xcos(phi)-ysin(phi)
        # y' = ycos(phi)+xsin(phi)
        direction = math.radians(direction)
        newCoordX = float(xcoord * math.cos(direction) - ycoord * math.sin(direction))
        newCoordY = float(ycoord * math.cos(direction) - xcoord * math.sin(direction))

        # move back the origin and return the coordinates
        newCoordX += origin[0]
        newCoordY += origin[1]
        return (newCoordX, newCoordY)

    # Function for processing real life UTM coordinates given image and image coordinates of
    #   detected plants.
    def processCoords(self, droneCoords, plantCoords, imageDims, direction):

        # type checking and performing necessary conversions for calculations
        tupleType = type((0,0))
        floatType = type(1.01)
        listType = type([1,2,3])
        if (type(droneCoords) == tupleType):
            tupleSize = len(droneCoords) # size of 2 means either geo or decimal coordinates.  4 is UTM
            if (tupleSize == 4):
                # convert the coordinates from UTM to decimal
                droneCoords = self.fromUTM(droneCoords)
            elif (tupleSize == 2):
                if (type(droneCoords[0]) == listType and len(droneCoords[0]) == 3):
                    # is geo coords.  Change to decimal for calculations
                    droneCoords = self.toDecimalDegrees(droneCoords)
                elif (type(droneCoords[0]) == floatType):
                    droneCoords = droneCoords # because a line of code needs to be here
                else:
                    return
            else:
                return
        else:
            return

        # defining and setting values for variables
        imageRatio = float(imageDims[0] / imageDims[1])
        edges = self.getEdges(droneCoords,imageRatio)
        imageOrigin = (imageDims[0]/2, imageDims[1]/2) # middle of the picture in image coords
        edgeN = edges[0]
        edgeE = edges[1]
        edgeS = edges[2]
        edgeW = edges[3]
        realCoordsX = 0 # these should not be 0 when returned
        realCoordsY = 0 # /
        latitude = droneCoords[0]
        longitude = droneCoords[1]

        # rotate coordinates along origin for direction
        # plantCoords = self.rotate(plantCoords, imageOrigin)
        xcoord, ycoord = self.rotate(plantCoords, imageOrigin, direction)

        #calculating distances and ratios
        distWE = math.fabs(edgeW[0] - edgeE[0])
        distNS = math.fabs(edgeN[1] - edgeS[1])
        xratio = float(xcoord/imageDims[0])
        yratio = float(ycoord/imageDims[1])
        ratioWE = distWE * xratio
        ratioNS = distNS * yratio

        # calculating coordinates with ratios
        if xcoord < imageOrigin[0]:
            realCoordsX = latitude + (distWE / 2) - (distWE * xratio)
        if xcoord > imageOrigin[0]:
            realCoordsX = edgeW[0] - (distWE * xratio)
        if xcoord == imageOrigin[0]:
            realCoordsX = latitude
        realCoordsY = edgeN[1] + (distNS * yratio)

        UTMcoords = self.toUTM((realCoordsX,realCoordsY))
        return ((realCoordsX, realCoordsY))


>>>>>>> Cleaned repository
pixelCoords = sys.argv[1] + "/Drone_coords.txt"
realCoords = sys.argv[1] + "/Real_coords.txt"
positiveDirectory = os.path.dirname(sys.argv[1] + '/Positive/')

<<<<<<< HEAD
<<<<<<< HEAD
c = crdfdr.CoordFinder(94,0,30) # 94 FOV, 0 direction, 30 meter height
=======
c = CoordFinder(94,0,30) # 94 FOV, 0 direction, 30 meter height
>>>>>>> Cleaned repository
=======
c = CoordFinder(94,30) # 94 FOV, 0 direction, 30 meter height
>>>>>>> Executables for python scripts to eliminate necessity for installation of python and tensorflow.
realC = open(realCoords, 'w+')
droneCoords = [0, 0]
plantCoords = [0, 0]
with open(pixelCoords) as f:
    for line in f:
        image_name, dir, droneCoords[0], droneCoords[1], sizex, sizey = line.split()
        for root, dirs, files in os.walk(positiveDirectory):
            for filename in fnmatch.filter(files, str("*"+image_name+"*")):
                plantCoords[0], plantCoords[1], rest = filename.split('_', 2)
                plant = c.processCoords((float(droneCoords[0]), float(droneCoords[1])), (float(plantCoords[0]), float(plantCoords[1])), (float(sizex), float(sizey)), 0)
                realC.write(str(rest) + ", " + str(plant[0]) + str(plant[1]) + str("\n"))

realC.close()
