#!/bin/bash

# This script is used for deploying the Virtual Machine (VM) project to a production environment

echo "Starting the deployment process..."

# Check if the VM is built
if [ ! -f "build/vm_executable" ]; then
    echo "VM executable not found. Please build the project first."
    exit 1
fi

# Set the deployment directory
DEPLOY_DIR="/opt/vm_project"

# Create the deployment directory if it doesn't exist
if [ ! -d "$DEPLOY_DIR" ]; then
    echo "Creating deployment directory at $DEPLOY_DIR..."
    sudo mkdir -p "$DEPLOY_DIR"
fi

# Copy the executable to the deployment directory
echo "Copying executable to $DEPLOY_DIR..."
sudo cp build/vm_executable "$DEPLOY_DIR/"

# Set appropriate permissions
echo "Setting permissions..."
sudo chmod +x "$DEPLOY_DIR/vm_executable"

# Optionally copy other configuration files (e.g., config.json, etc.)
echo "Copying configuration files..."
sudo cp config.json "$DEPLOY_DIR/"

# Notify the user that deployment is complete
echo "Deployment complete. The VM is now deployed to $DEPLOY_DIR."

# Optionally, you can start the VM as a background process
echo "Starting the VM..."
nohup "$DEPLOY_DIR/vm_executable" > /dev/null 2>&1 &
echo "VM is running in the background."
