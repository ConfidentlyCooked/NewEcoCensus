EcoCensus

In order to use the current implementation of EcoCensus, the installation of TensorFlow and Python is no longer required. The current implementation of EcoCensus is contained in the folder EcoCensus03122018. The folder CurrentImplementation03092018 within EcoCensus03122018 contains the UI code. The Scripts folder contains the current python code for creating a convolutional neural network for the classification and location of invasive or endangered species, currently focusing on Miconia only. Scripts contains the five python files, dataset.py, image_partition.py, predict.py, predictions.py, train.py, get_lat_lon_exif_pil.py, imageReader.py, and coordFinder.py which are vital for the creation of the convolutional neural network as well as classification and locating of plant species within images. The dist folder contains the bundled folders with executables of the python scripts with their dependencies, so no installation of Python, Tensorflow, OpenCV, or any of the other libraries used is needed. All paths no longer need to be reconfigured by the user to work with whatever directories, except for the training data which the user desires, since the executables in dist are currently performing all of the analysis and processing. The file dataset.py loads in the images and prepares them for training the convolutional neural network. The file image_partition.py partitions images into a three hundred by three hundred pixel partitions and saves these partitions to a temporary Partitions directory in the specified output directory. The predictions.py file specifies a folder of images to classify and creates folders with the classified images. The train.py file trains the convolutional neural network using the training dataset it is provided with a hold out set and validation, tracking the loss.

The following are instructions for running the current implementation of EcoCensus, which is currently Mac compatible and contained in EcoCensus/EcoCensus03122018/CurrentImplementation03092018/EcoCensus.app/Contents/MacOS/ where the executable is EcoCensus and dist contains necessary executables for EcoCensus’s running:
    
    1.  You must request the complete version of the app from Rebekah Loving as a single file is missing from two of the executables which EcoCensus is dependent on due to file size being too large for the free version of GitHub. 
    2.  Download the EcoCensus.app folder.
    3.  Run EcoCensus by double-clicking the EcoCensus.app folder which opens the executable.
    4.  Currently, only the Classify and Coordinates tabs have full functionality. 
        a.  To classify images, click on the Classify tab:
            i.  Click on the Images Directory button
                1.  Select the desired directory of .JPEG files to classify
            ii. Click on the Classified Directory button 
                1.  Select the desired directory for outputting classified partitions to as well as the calculated coordinates of positively classified partitions
            iii.    Click Partition and Predict button
                1.  Currently, a hundred photos takes slightly less than ten minutes to process
            iv. When classification is complete the window below Partition and Predict will be populated with images, scroll and click through these images to see the results in the viewer on the right, using + and - for zoom and fit to return to the original view as necessary. 
        b.  To view the coordinates, click on the Coordinates tab:
            i.  Click on the Real_Coords.txt for the GPS coordinates of the positive partitions in the selected images.
            ii. Click on the Drone_Coords.txt for the GPS coordinates from the location of the drone for each image. 
