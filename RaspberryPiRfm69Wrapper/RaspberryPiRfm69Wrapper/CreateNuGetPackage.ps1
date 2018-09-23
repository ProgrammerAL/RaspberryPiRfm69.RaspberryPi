Param(
  [string]$projectDir, #= "C:\VSTS\LaserTag\LinuxApps\RaspberryPiRfm69Wrapper\RaspberryPiRfm69Wrapper"
  [string]$targetPlatform, #= "ARM"
  [string]$buildConfiguration #= "Release"
)


$rootDir = "$projectDir/../../../"
$targetDir = "$rootDir/SmartAppLayer/RaspberryPiControl/NativeLibs"

$compiledFilesDir = "$projectDir/bin/$targetPlatform/$buildConfiguration/"

#Copy the compiled dynamic library file to the directory used by the RaspberryPiControl project
Get-ChildItem $compiledFilesDir | Copy-Item -Destination $targetDir

