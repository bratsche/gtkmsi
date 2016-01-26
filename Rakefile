require 'optparse'

task :default => ['msi:build']

namespace :msi do
  task 'gtk-sharp-2.0.wxs' do
    sh "erb version=\"#{version}\" gtk-sharp-2.0.wxs.erb > gtk-sharp-2.0.wxs"
  end

  task 'unmanaged/bundle-scanner.exe' do
    'csc bundle-scanner.cs'
  end

  task 'unmanaged/redirector.exe' do
    'csc redirector.cs'
  end

  task :scan_unmanaged => ['unmanaged/bundle-scanner.exe'] do
    sh './unmanaged/bundle-scanner.exe --wix=unmanaged/unmanaged.wxs --bundle=source'
  end

  task 'unmanaged/unmanaged.wixobj' => ['unmanaged/redirector.exe'] do
    sh 'candle unmanaged/unmanaged.wxs'
  end

  task :build => [:clean, 'gtk-sharp-2.0.wxs', 'unmanaged/unmanaged.wixobj'] do
    sh "candle -ext WixUIExtension gtk-sharp-2.0.wxs"
    sh "light -cultures:en-us -ext WixUIExtension -ext WixNetFxExtension -out gtk-sharp-#{version}.msi gtk-sharp-2.0.wixobj"
  end

  task :clean do
  end

  def options
    opts = {}

    OptionParser.new do |o|
      o.banner = "Usage: rake msi:build [options]"
      o.on("-v", "--version ARG", String) { |v| options[:version] = v }
    end.parse!

    opts
  end

  def version
    options[:version]
  end
end

