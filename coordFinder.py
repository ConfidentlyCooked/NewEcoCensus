"""
EcoCensus Coordinate Converter
Copyright 2018: Morgan West, Rebekah Loving
"""

import math
import utm

# This class will take the x,y coordinates of fauna found in a given
# image and output the real world coordinates.
# This class will be called per image list with identical non-metadata variables eg FOV, direciton.
class CoordFinder:

    def __init__(self,FOV,height):
        self.theta = float(FOV / 2)
        self.droneHeight = height # in meters
        return

    # Converts coordinates from geographic to decimal degrees
    # Used because coordinates stored in image metadata are in geographic form
    def toDecimalDegrees(self,droneCoords):      
        # Geographic coords stored as tuple of lists ([hours,minutes,seconds],[hours,minutes,seconds])
        # Conversion formula is (hr + (min/60) + (sec/3600))
        latitude = droneCoords[0]
        longitude = droneCoords[1]
        newLatitude = float(latitude[0] + float(latitude[1] / 60) + float(latitude[2] / 3600))
        newLongitude = float(longitude[0] + float(longitude[1] / 60) + float(longitude[2] / 3600))
        if newLongitude > 0: # doing this for the western hemisphere.  Take out statement for eastern
            newLongitude = newLongitude * -1
        return (newLatitude,newLongitude)

    # Converts decimal degrees to universal transverse mercador in zone 5Q (Big Island).
    # Returns a coordinate tuple in UTM.
    def toUTM(self,coords):
        # Conversion
        latitude = coords[0]
        longitude = coords[1]
        return utm.from_latlon(latitude,longitude) # see documentation for utm library

    # Takes in UTM coordinates and outputs decimal degree coordinates
    def fromUTM(self,coords):
        # Conversion
        return utm.to_latlon(coords)

    # Takes the coordinate given from the image data and calculates the edge
    def getEdges(self,droneDD,imageRatio):
        # defining and setting variables
        droneLat = droneDD[0]
        droneLong = droneDD[1]
        edges = [] # list of edges [top, right, bottom, left]
        distToEdge = float(self.droneHeight*math.tan(self.theta))
        
        # conversion from meters to decimal degrees
        # 1 m = 0.0004858 dd
        distToEdge = float(distToEdge * 0.0004858)

        # edge calculations assuming orientation is north-up
        NSdistToEdge = float(distToEdge / imageRatio) # since the image is wider than it is tall
##        northx = droneLat
##        northy = droneLong + NSdistToEdge 
##        westx = droneLat + distToEdge
##        westy = droneLong
##        southx = droneLat
##        southy = droneLong - NSdistToEdge
##        eastx = droneLat - distToEdge
##        easty = droneLong
        NSDistance = 2*NSdistToEdge
        WEDistance = 2*distToEdge

        # add coordinates to list in NESW order
##        edges.append((northx,northy))   # N
##        edges.append((westx,westy))     # E
##        edges.append((southx,southy))   # S
##        edges.append((eastx,easty))     # W
        return (WEDistance, NSDistance)

    # Finds the midpoint of the coordinates calculated for multiple images that contain the same
    #   geographic location.
    def midpoint(self,coordinates):
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
        # change image coordinates to emulate the center of the image as (0,0)
        xcoord = float(coords[0] - origin[0])
        ycoord = float(coords[1] - origin[1])

        # rotate coordinates around new origin
        # x' = xcos(phi)-ysin(phi)
        # y' = ycos(phi)+xsin(phi)
        direction = math.radians(direction)
        newCoordX = float(xcoord * math.cos(direction) - ycoord * math.sin(direction))
        newCoordY = float(ycoord * math.cos(direction) + xcoord * math.sin(direction))

        # move back the origin and return the coordinates
        newCoordX += origin[0]
        newCoordY += origin[1]      
        return (newCoordX, newCoordY)
    
    # Function for processing real life UTM coordinates given image and image coordinates of
    #   detected plants.
    def processCoords(self, droneCoords, plantCoords, imageDims, direction):

##        # type checking and performing necessary conversions for calculations
##        tupleType = type((0,0))
##        floatType = type(1.01)
##        listType = type([1,2,3])
##        if (type(droneCoords) == tupleType):
##            tupleSize = len(droneCoords) # size of 2 means either geo or decimal coordinates.  4 is UTM
##            if (tupleSize == 4):
##                # convert the coordinates from UTM to decimal
##                droneCoords = self.fromUTM(droneCoords)
##            elif (tupleSize == 2):
##                if (type(droneCoords[0]) == listType and len(droneCoords[0]) == 3):
##                    # is geo coords.  Change to decimal for calculations
##                    droneCoords = self.toDecimalDegrees(droneCoords)
##                elif (type(droneCoords[0]) == floatType):
##                    droneCoords = droneCoords # because a line of code needs to be here
##                else:
##                    return
##            else:
##                return
##        else:
##            return
        droneCoords = self.toDecimalDegrees(droneCoords)
        print(self.toUTM(droneCoords))
        # defining and setting values for variables
        imageRatio = float(imageDims[0] / imageDims[1])
##        edges = self.getEdges(droneCoords,imageRatio)
        imageOrigin = (imageDims[0]/2, imageDims[1]/2) # middle of the picture in image coords
##        edgeN = edges[0]
##        edgeE = edges[1]
##        edgeS = edges[2]
##        edgeW = edges[3]
        WEDistance, NSDistance = self.getEdges(droneCoords,imageRatio)
        realCoordsX = 0 # these will be the final coordinates
        realCoordsY = 0 # /
        latitude = droneCoords[0]
        longitude = droneCoords[1]

        # rotate coordinates along origin for direction
        xcoord, ycoord = self.rotate(plantCoords, imageOrigin, direction)
        
        #calculating distances and ratios
##        distWE = math.fabs(edgeW[0] - edgeE[0])
##        distNS = math.fabs(edgeN[1] - edgeS[1])
        xratio = float(xcoord/imageDims[0])
        yratio = float(ycoord/imageDims[1])
        ratioWE = WEDistance * xratio
        ratioNS = NSDistance * yratio

        # calculating coordinates with ratios
##        if xcoord < imageOrigin[0]:
##            realCoordsX = latitude + (distWE / 2) - (distWE * xratio)
##        if xcoord > imageOrigin[0]:
##            realCoordsX = edgeW[0] - (distWE * xratio)
##        if xcoord == imageOrigin[0]:
##            realCoordsX = latitude
        realCoordsX = droneCoords[0] + (0.5*NSDistance) - ratioNS
        realCoordsY = droneCoords[1] - (0.5*WEDistance) + ratioWE

        UTMcoords = self.toUTM((realCoordsX,realCoordsY))
        return ((realCoordsX, realCoordsY))
                
