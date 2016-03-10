require 'optparse'

task :default => ['msi:build']

namespace :unmanaged do
  task :scanner do
    sh 'csc bundle-scanner.cs'
  end

  task :redirector do
    sh 'csc redirector.cs'
  end

  task :wixobj => [:redirector] do
    sh 'candle unmanaged.wxs'
  end

  task :msm => [:wixobj] do
    sh 'light unmanaged.wixobj'
  end

  task :scan => [:scanner] do
    sh './bundle-scanner.exe --wix=unmanaged.wxs --bundle=source'
  end
end

namespace :msi do
  file 'gtk-sharp-2.0.wxs' do
    sh "erb version=\"#{version}\" gtk-sharp-2.0.wxs.erb > gtk-sharp-2.0.wxs"
  end
  
  task :update do
    puts 'Updating updateinfo'
    productid, build = File.read('updateinfo').strip.split
    padded_version = version.split('.').collect { |n| n.rjust(3, '0') }.join
    last_version_change = `git blame HEAD VERSION`.split.first
    commit_distance = `git rev-list #{last_version_change}..HEAD --count`.strip.rjust(3, '0')
    newbuild = padded_version + commit_distance
    File.open('updateinfo', 'w') do |f|
      f.puts "#{productid} #{newbuild}" 
    end 
  end
   
   task :unmanaged do
     Dir.chdir 'unmanaged' do
       Rake::Task['unmanaged:msm'].invoke
     end
   end

  task :build => [:clean, :update, 'gtk-sharp-2.0.wxs', :unmanaged] do
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
    options[:version] || File.read("VERSION").chop
  end
end
