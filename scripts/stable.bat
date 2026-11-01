@echo off

:: To be used for curl -fsSL https://setup.nekernel.org

echo "==> NE.APP: WELCOME TO THE NEANT STABLE PDK."
echo "==> NE.APP: INSTALLING PDK..."
echo "==> NEW: ANT IS NOW AVAILABLE AS A STANDALONE OS DISTRIBUTION AND PDK."

echo "==> COMING SOON: ANT AND NEANT DRIVERS REPOSITORY WILL SOON BE AVAILABLE."

set ARCH=x64
set PROFILE=release-efi-pc

set SRC=src
set KRNL=krnl
set NEBUILD=bld
set NCC=ncc
set VCS=git
set FLAGS=clone
set DIST=src-%ARCH%-%PROFILE%

mkdir %DIST%

%VCS% %FLAGS% https://github.com/ne-app-open/%SRC%.git -b stable %DIST%\%SRC%
%VCS% %FLAGS% https://github.com/ne-app-open/%KRNL%.git -b stable %DIST%\%KRNL%
%VCS% %FLAGS% https://github.com/ne-app-open/%NEBUILD%.git -b stable %DIST%\%NEBUILD%
%VCS% %FLAGS% https://github.com/ne-app-open/%NCC%.git -b stable %DIST%\%NCC%

cd %DIST%

echo "==> DONE."
