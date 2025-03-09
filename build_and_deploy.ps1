# Define paths
$clionBuildDir = "C:\Users\jf160343d\CLionProjects\RouteOptimizationAPI\cmake-build-android"
$soFileSource = "$clionBuildDir\libRouteOptimizationAPI.so"
$androidLibsDir = "C:\Users\jf160343d\Desktop\RouteOptimizationApp\app\src\main\jniLibs\arm64-v8a"
$soFileDest = "$androidLibsDir\libRouteOptimizationAPI.so"

# Ensure the target directory exists
if (-not (Test-Path $androidLibsDir)) {
    Write-Host "Creating directory: $androidLibsDir"
    New-Item -ItemType Directory -Path $androidLibsDir -Force
}

# Build the project
Write-Host "Building CLion project..."
cmake --build $clionBuildDir

# Check if the .so file was created
if (Test-Path $soFileSource) {
    Write-Host "Build successful! Copying .so file..."

    # Copy .so file to Android Studio project
    Copy-Item -Path $soFileSource -Destination $soFileDest -Force

    # Verify copy
    if (Test-Path $soFileDest) {
        Write-Host "✅ Library successfully copied to Android Studio project!"
    } else {
        Write-Host "❌ Error: The .so file was not copied successfully!"
    }
} else {
    Write-Host "❌ Build failed: The .so file was not found at $soFileSource"
}
